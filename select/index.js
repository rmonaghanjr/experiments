import fs from "fs";
import chalk from "chalk";

function argv(index) {
    return process.argv[index + (ENV == "NODE" ? 1 : 0)];
}

const ENV = process.argv[0].includes("node") ? "NODE" : "EXECUTABLE";
const USAGE = "Usage: " + (ENV == "NODE" ? "node " : " ") + argv(0).replace(/^.*[\\\/]/, '') + " <number> [filepath]";

let data = "";
let lines = "";
let selections = 0;

function parseArgs(data) {
    let argc = process.argv.length;
    if (ENV == "NODE") argc--;

    if (argc == 1 || (argc == 2 && data == "") || argc > (3 - (process.stdin.isTTY ? 0 : 1))) {
        console.log(USAGE);
        return;
    }

    if (data == "" && fs.existsSync(argv(2))) {
        data = fs.readFileSync(argv(2).replace(/^.*[\\\/]/, ''), "utf8");
    } else if (data == "") {
        console.error("Error: File '"+argv(2)+"' does not exist.");
        console.log(USAGE);
        return;
    }
    data = data.split("\n");

    selections = parseInt(argv(1));
    if (selections == 0) {
        selections = data.length - 1;
    }
    
    let removals = 0;
    for (let i = 0; i < data.length; i++) {
        if (data[i] == "") {
            data.splice(i, 1);
            i--;
            removals++;
        }
    }
    selections -= removals;

    return data;
}

function weightLines(lines) {
    let weights = {};
    let keys = [];
    let sums = [0];
    let sum = 0.0;
    let remainder = 1.0;
    let distribution = 0.0;
    let weightedLines = 0
    
    for (let i = 0; i < lines.length; i++) {
        if (!lines[i].includes("|")) continue;
        let value = lines[i].split("|")[1];
        let weight = 0.0;

        if (value.includes("%", "")) {
            weight = parseFloat(lines[i].split("|")[1].replace("%", ""));
        } else {
            weight = parseFloat(lines[i].split("|")[1]);
        }
        weight /= 100.0;

        sum += weight; 
        remainder -= weight; 
        weightedLines++;

        weights[i] = weight;
    }

    if (sum > 1.0 && remainder < 0.0) {
        console.error("Invalid weighting in the files!");
        process.exit(1);
    }

    distribution = remainder / (lines.length - weightedLines);

    for (let i = 0; i < lines.length; i++) {
        let name = lines[i].split("|")[0];
        keys.push(name);
        if (lines[i].includes("|")) {
            sums.push(sums[sums.length - 1] + weights[i]);
        } else {
            sums.push(sums[sums.length - 1] + distribution);
        }
    }
    sums.splice(0, 1);

    return [keys, sums];
}

function binarySearch(probabilities, target, low, high) {
    let mid = Math.floor((low + high) / 2)
    if (low == high) return low;

    if (target < probabilities[mid]) {
        return binarySearch(probabilities, target, low, mid); 
    } else if (target > probabilities[mid]) {
        return binarySearch(probabilities, target, mid + 1, high);
    } else {
        return mid;
    }
}

function selectItem(lines) {
    let [keys, sums] = weightLines(lines);
    let i = binarySearch(sums, Math.random(), 0, sums.length - 1); 

    return keys[i];
}

function selectLines(lines, count) {
    console.log(chalk.cyan(chalk.bold("selecting ")+chalk.underline(chalk.bold(count))+chalk.bold(" items...")));

    for (let i = 0; i <= count; i++) {
        let selected = selectItem(lines);
        
        let rm = 0;
        for (let j = 0; j < lines.length; j++) {
            if (lines[j].includes(selected)) {
                rm = j;
                break;
            }
        }
        lines.splice(rm, 1);

        console.log(chalk.bold(chalk.cyan((i + 1)+"")+":")+" "+chalk.red(selected));
    }
}

if (!process.stdin.isTTY) {
    process.stdin.on("readable", () => {
        let chunk = "";

        while ((chunk = process.stdin.read()) != null) {
            data += chunk;
        }
    });

    process.stdin.on("end", () => {
        lines = parseArgs(data);
        selectLines(lines, selections);
    });
} else {
    lines = parseArgs(data);
    selectLines(lines, selections);
}

