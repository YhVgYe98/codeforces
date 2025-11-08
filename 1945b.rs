
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
     
fn main() {
    let question_size = read_num::<i32>();
    for _ in 0..question_size {
        let meta = read_vec::<i32>();
        let (r, c, num, distance) = (meta[0], meta[1], meta[2], meta[3]);
        let mut costs: Vec<i32> = Vec::with_capacity(r as usize);
        let mut _temp: Vec<Vec<i32>> = vec![];
        for _ in 0..r as usize {
            let temp = read_vec::<i32>();
            costs.push(min_cost(&temp, distance+1));
        }
        costs.sort();
        println!("{}",&costs[..num as usize].iter().sum::<i32>());
    }
}
 
fn min_cost(depths: &Vec<i32>, range: i32) -> i32 {
    let range = range as usize;
    let mut res: Vec<i32> = Vec::with_capacity(depths.len()+1);
    res.push(1);
    for i in 1..depths.len() {
        res.push(1 + depths[i] + *res[if i>range {i-range} else {0}..].iter().min().unwrap());
    }
    *res.last().unwrap()
}
