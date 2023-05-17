pub fn bubble_sort(l: &mut [usize]) {
    if l.is_empty() {
        return;
    }

    let mut sorted = false;
    let mut n = l.len();
    while !sorted {
        sorted = true;
        for i in 0..n - 1 {
            if l[i] > l[i + 1] {
                l.swap(i, i + 1);
                sorted = false;
            }
        }
        n -= 1;
    }
}

pub fn insertion_sort(l: &mut [usize]) {
    if l.is_empty() {
        return;
    }

    for i in 1..l.len() {
        let mut j = i;
        while j > 0 && l[j-1] > l[j] {
            l.swap(j, j - 1);
            j -= 1;
        }
    }
}
