class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto c : data) 
        {
            // means first digit of array
            if (count == 0) 
            {
                //means current is 2byte and next should be 10
                if ((c >> 5) == 0b110) 
                    count = 1;
                // current is 3byte and next should be 2
                else if ((c >> 4) == 0b1110) 
                    count = 2;
                // current is 4 byte and next should be 3
                else if ((c >> 3) == 0b11110) 
                    count = 3;
                
                else if ((c >> 7)) 
                    return false;
            } 
            else 
            {
                if ((c >> 6) != 0b10) 
                    return false;
                count--;
            }
        }
        return count == 0;
    }
};