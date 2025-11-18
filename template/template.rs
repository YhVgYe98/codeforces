
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
fn solution() {
    //TODO
}


fn main() {
    for _ in 0..read_num::<usize>() {
        solution();
    }
}
