
use std::thread;

fn main() {
    let top = 1000 * 1000 * 1000;

    let mut kids = vec![];

    for tt in 0..10 {
        kids.push(thread::spawn(move || {
            let mut local_sum: i64 = 0;
            
            let i0 = tt * (top / 10);
            let i1 = i0 + (top / 10);

            for ii in i0..i1 {
                if ii % 101 == 0 {
                    local_sum += ii;
                }
            }

            local_sum
        }));
    }

    let mut sum: i64 = 0;
    for th in kids {
        sum += th.join().unwrap();
    }

    println!("sum: {}", sum);
}
