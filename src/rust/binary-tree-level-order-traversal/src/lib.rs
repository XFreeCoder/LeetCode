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
        fn traversal(root: &Option<Rc<RefCell<TreeNode>>>, ans: &mut Vec<Vec<i32>>, level: usize) {
            let root_node = match root {
                Some(it) => it,
                _ => return,
            };
            if ans.len() == level {
                ans.push(Vec::new());
            }
            ans[level].push(root_node.borrow().val);
            traversal(&root_node.borrow().left, ans, level + 1);
            traversal(&root_node.borrow().right, ans, level + 1);
        }

        let mut ans: Vec<Vec<i32>> = Vec::new();
        traversal(&root, &mut ans, 0);

        ans
    }
}

#[cfg(test)]
mod tests {
    use std::cell::RefCell;
    use std::rc::Rc;

    use super::Solution;
    use super::TreeNode;

    fn make_tree_node(
        val: Option<i32>,
        left: Option<Rc<RefCell<TreeNode>>>,
        right: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match val {
            Some(val) => {
                let mut node = TreeNode::new(val);
                node.left = left;
                node.right = right;
                Some(Rc::new(RefCell::new(node)))
            }
            None => None,
        }
    }

    fn _make_tree(vec: &Vec<Option<i32>>, root_index: usize) -> Option<Rc<RefCell<TreeNode>>> {
        let val = vec.get(root_index);
        match val {
            Some(val) => make_tree_node(
                *val,
                _make_tree(vec, 2 * root_index + 1),
                _make_tree(vec, 2 * root_index + 2),
            ),
            None => None,
        }
    }

    fn make_tree(vec: &Vec<Option<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        _make_tree(vec, 0)
    }

    #[test]
    fn test_make_tree() {
        let vec = vec![Some(3), Some(9), Some(20), None, None, Some(15), Some(7)];
        let root = make_tree(&vec);
        let expect = make_tree_node(
            Some(3),
            make_tree_node(Some(9), None, None),
            make_tree_node(
                Some(20),
                make_tree_node(Some(15), None, None),
                make_tree_node(Some(7), None, None),
            ),
        );
        assert_eq!(root, expect);
    }

    #[test]
    fn test1() {
        let root = make_tree(&vec![
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
        let root = make_tree(&vec![Some(1)]);
        assert_eq!(Solution::level_order(root), vec![vec![1]]);
    }

    #[test]
    fn test3() {
        let root = make_tree(&vec![]);
        assert_eq!(Solution::level_order(root), vec![] as Vec<Vec<i32>>);
    }
}
