
//commented code with explanation

class MyCircularDeque {
public:
    vector<int> q;
    int front,rear;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        q.resize(k,0); //resizing the vector(arraysize) with the given size k.
        front=-1; //intially front and rear both points to the -1 location as in case of circular queue happens.
        rear=-1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()){ //checking for queue is full or not.
            return false;
        }
        else{
            if(front==-1){ //in case we are pushing the element in the queue for the first time.
                insertLast(value);
            }
            else{
                front=(front+(q.size()-1))%q.size(); //by this formula front will move to the 1 pos back where it is currently if it is on 0th postion then it will take the last index (Nth) location of the array/vector. just use copy pen and tried this out.
                q[front]=value; //put the value in q of front newly location 
            }
        }
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()){ //checking for queue is full or not.
            return false;
        }
        else{
            if(front==-1){ //in case we are pushing the element in the queue for the first time.
                front=0;
            }
            rear=(rear+1)%q.size(); //move rear by 1 location after where it is currently. If rear is on Nth location of the index in the array then it will move to the 0th location of the array. Remember we have alreay checked for the array full cond. in above if condition.just use copy pen and tried out this formula. 
            q[rear]=value;
        }
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        else{
            if(front==rear){ //if there is only 1 element in the queue.
                front=-1;
                rear=-1;
            }
            else{
                front=(front+1)%q.size();  //moving front by 1
            }
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        else{
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{
                rear=(rear+(q.size()-1))%q.size();
            }
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return q[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if((rear+1)%q.size()==front){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */