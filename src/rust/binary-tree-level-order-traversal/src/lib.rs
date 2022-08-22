use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

pub struct Solution {}

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        todo!("level_order");
    }
}

#[cfg(test)]
mod tests {
    use std::cell::RefCell;
    use std::rc::Rc;

    use super::Solution;
    use super::TreeNode;

    fn get_tree_node(val: Option<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        return match val {
            Some(val) => Some(Rc::new(RefCell::new(TreeNode::new(val)))),
            None => None,
        };
    }

    fn build_tree_from_vec(vec: Vec<Option<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        todo!("build_tree_from_vec");
    }

    #[test]
    fn test1() {
        let root = build_tree_from_vec(vec![
            Some(3),
            Some(9),
            Some(20),
            None,
            None,
            Some(15),
            Some(7),
        ]);
        assert_eq!(
            Solution::level_order(root),
            vec![vec![3], vec![9, 20], vec![15, 7]]
        );
    }

    #[test]
    fn test2() {
        let root = build_tree_from_vec(vec![Some(1)]);
        assert_eq!(Solution::level_order(root), vec![vec![1]]);
    }

    #[test]
    fn test3() {
        let root = build_tree_from_vec(vec![]);
        assert_eq!(Solution::level_order(root), vec![] as Vec<Vec<i32>>);
    }
}
