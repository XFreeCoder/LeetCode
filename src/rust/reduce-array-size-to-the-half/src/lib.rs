use std::collections::HashMap;

pub struct Solution {}

impl Solution {
    pub fn min_set_size(arr: Vec<i32>) -> i32 {
        let mut counter = HashMap::new();

        arr.iter().for_each(|&x| {
            let count = counter.entry(x).or_insert(0);
            *count += 1;
        });

        let total_count = arr.len();
        let mut counting = vec![0; total_count + 1];
        counter
            .values()
            .for_each(|&freq| counting[freq as usize] += 1);

        let (mut ans, mut removed, mut freq, half) = (0, 0, total_count, total_count / 2);
        while removed < half {
            ans += 1;
            while counting[freq] == 0 {
                freq -= 1;
            }
            removed += freq;
            counting[freq] -= 1;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test1() {
        assert_eq!(
            Solution::min_set_size(vec![3, 3, 3, 3, 5, 5, 5, 2, 2, 7]),
            2
        );
    }

    #[test]
    fn test2() {
        assert_eq!(Solution::min_set_size(vec![7, 7, 7, 7, 7, 7]), 1);
    }
}
