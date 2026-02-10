class Solution {
    public boolean isValid(String s) {
        //using stack to compare the chars
        Stack<Character> stack = new Stack<>();

        //the only loop, leading to an O(n) time complexity
        for (char c : s.toCharArray()){
            if (c=='('||c=='['||c=='{'){
                //ignoring the opening chars from the stack
                stack.push(c);
            }else{
                //if we dont have none of the parentheses, is not valid
                if (stack.isEmpty()) return false;
                //comparing the opening chars with the ones that are remaining in the stack
                char top = stack.pop();
                if (c==')' && top!='(') return false;
                if (c==']' && top!='[') return false;
                if (c=='}' && top!='{') return false;
            }
        }
        // if the stack is empty, all the pairs were closed
        return stack.isEmpty();
    }
}