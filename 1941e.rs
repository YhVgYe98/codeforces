//------------- common fun ------------------
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
    let question_size = read_num::<i64>();
    for turn in 0..question_size {
        let meta = read_vec::<i64>();
        let (r, c, num, distance) = (meta[0], meta[1], meta[2], meta[3]);
        let mut costs: Vec<i64> = Vec::with_capacity(r as usize);
        for _ in 0..r as usize {
            let temp = read_vec::<i64>();
            costs.push(min_cost(&temp, distance+1));
        }
        // println!("{:?}",costs);
        let mut temp_sum = costs[..num as usize].iter().sum::<i64>();
        let mut ac = temp_sum;
        for i in num as usize..r as usize {
            temp_sum = temp_sum-costs[i-(num as usize)]+costs[i];
            ac = temp_sum.min(ac);
        }
        
        println!("{}\r",ac);
    }
}
 
fn min_cost(depths: &Vec<i64>, range: i64) -> i64 {
    let range = range as usize;
    let mut res: Vec<i64> = Vec::with_capacity(depths.len()+1);
    res.push(1);
    let mut range_min = std::collections::BTreeMap::new();
    range_min.insert(1, 1);
    let mut range_min_len = 1;
    for i in 1..depths.len() {
        // res.push(1 + depths[i] + *res[if i>range {i-range} else {0}..].iter().min().unwrap());
        res.push(1 + depths[i] + range_min.first_key_value().unwrap().0);
        let now_cost = res.last().unwrap();
        match range_min.get(now_cost) {
            None => range_min.insert(*now_cost, 1),
            Some(x) => range_min.insert(*now_cost, x+1),
        };
        range_min_len += 1;
        // min_range.insert(min_range.binary_search(&now_cost).unwrap()+1, res.last().unwrap().clone());
        if range_min_len>range {
            range_min_len -= 1;
            let value_to_delete = &res[i-range as usize];
            if range_min.get(value_to_delete).unwrap() == &1 {
                range_min.remove(value_to_delete);
            } else {
                range_min.insert(*value_to_delete, range_min.get(value_to_delete).unwrap()-1);
            }
        }
    }
    *res.last().unwrap()
}