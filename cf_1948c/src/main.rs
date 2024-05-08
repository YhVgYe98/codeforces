use std::collections::HashMap;

//------------- utility fun ------------------
fn read_vec<T>() -> Vec<T>
where
    T: std::str::FromStr,
    <T as std::str::FromStr>::Err: std::fmt::Debug,
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input
        .trim()
        .split(' ')
        .map(|x: &str| x.parse::<T>().unwrap())
        .collect()
}

fn read_num<T>() -> T
where
    T: std::str::FromStr,
    <T as std::str::FromStr>::Err: std::fmt::Debug,
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().parse::<T>().unwrap()
}
//----------------------------------------------
fn solution(trans_state: &HashMap<i32, i32>) {
    let mut line1 = String::new();
    let mut line2 = String::new();
    let case_len: usize = read_num();
    std::io::stdin().read_line(&mut line1).unwrap();
    std::io::stdin().read_line(&mut line2).unwrap();
    let line1: Vec<char> = line1.chars().collect();
    let line2: Vec<char> = line2.chars().collect();

    let mut now_reachable = 9;
    for i in 0..case_len - 2 {
        let now_state = (((line1[i] == '>') as i32) << 7)
            + (((line2[i] == '>') as i32) << 6)
            + (((line1[i+1] == '>') as i32) << 5)
            + (((line2[i + 1] == '>') as i32) << 4)
            + now_reachable;
            now_reachable = *trans_state.get(&now_state).expect("no value in table");
    }
    if (now_reachable & 0b0111) != 0 {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    let mut trans_state: HashMap<i32, i32> = HashMap::new();
    for first_col in 0..4 {
        for second_col in 0..4 {
            let mut can_reach;
            for first_reachable in 0..4 {
                for second_reachable in 0..4 {
                    can_reach = second_reachable << 2;
                    if second_col >> 1 == 1
                        && (first_reachable >> 1 == 1 || second_reachable & 1 == 1)
                    {
                        can_reach |= 1 << 1;
                    }
                    if second_col & 1 == 1
                        && (first_reachable & 1 == 1 || second_reachable >> 1 == 1)
                    {
                        can_reach |= 1;
                    }
                    trans_state.insert(
                        (first_col << 6)
                            + (second_col << 4)
                            + (first_reachable << 2)
                            + (second_reachable),
                        can_reach,
                    );
                }
            }
        }
    }
    for _ in 0..read_num::<usize>() {
        solution(&trans_state);
    }
}
