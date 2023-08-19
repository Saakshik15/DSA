/*
Problem Statement :

We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction 
(positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/

/*
Solution :

Approach : using monotonic stack

explained the approach in the comments of the code
*/

//code :

vector<int> asteroidCollision(vector<int>& asteroids) {
    
    stack<int> stk;

    for(int i=0; i<asteroids.size(); i++){

        //if stack is empty then in all cases, including current value to be negative the value will be pushed onto the stack
        //or even if the current value is positive, push it on stack as current positive value will not collide with a previous negative value 
        //ie, [-5,5] will not collide as -5 is towards left and +5 is right
        if(stk.empty() || asteroids[i] > 0) 
            stk.push(asteroids[i]);

        else{
            //in the case where stack is not empty and the current value is a negative integer
            while(true){
                //using while(true) loop in case if there are multiple negative values in the stack, the loop will continue
                int top= stk.top();
                if(top<0){
                    //if the top of the stack is also a negative integer, the asteroids will not collide as they are in same direction 
                    //and we will push current(negative) value on stack
                    stk.push(asteroids[i]);
                    break;
                } 
                else if(top == -asteroids[i]){
                    //in case where top is negative and it is equal to the current positive value
                    //eg, if top = -5 and current value is 5, then -5 == -(5)
                    //then we will pop the top value of stack as they will collide and cancel out each other
                    stk.pop();
                    break;
                }
                else if(top > -asteroids[i]){
                    //in the case where top is positive, and current negative value cannot cancel out the positive at the top, 
                    //then we will do nothing as the current negative value will be cancelled out by positive at the top
                    //eg. if top=5 and current value= -4, thus, 5 > -(-4) so -4 will be cancelled out so we will do nothing in this case
                    break;
                }
                else{
                    //in this case, the top is a positive value and the current negative value of asteroid is greater than the positive top
                    //eg. the stack is [-2,5,4,3,2,1] and current value = -4, thus, all the elements 1,2,3,4 will be cancelled out by -4 as numerically -4 is greater
                    //thus, to continue popping these elements till the condition is false, we have used a while(true) loop and 
                    //it will be false only when any of the above condition is being executed or when the stack is empty.
                    stk.pop();
                    if(stk.empty()) {
                        //if stack is empty, in case where stack = [3,2,1] and current value = -4 then all elements will be popped
                        //we will push current element on stack and break the while(true) loop.
                        stk.push(asteroids[i]);
                        break;
                    }
                }
            }
        }
    }
    //we will then store all elements of stack on the vector reversing the order as the stack is storing the elements in reverse
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}












