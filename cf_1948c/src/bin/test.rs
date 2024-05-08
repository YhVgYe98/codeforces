fn main() {
    for first_col in 0..4 {
        for second_col in 0..4 {
            for first_reachable in 0..4 {
                for second_reachable in 0..4 {
                    println!(
                        "{}",
                        (first_col <<6)
                            + (second_col <<4)
                            + (first_reachable <<2)
                            + (second_reachable)
                    );
                }
            }
        }
    }
}
