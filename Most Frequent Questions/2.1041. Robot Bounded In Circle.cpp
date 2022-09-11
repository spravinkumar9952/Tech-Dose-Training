class Solution {
public:
    bool isRobotBounded(string instructions) {
        int deg = 0;
        int x = 0, y = 0;
        
        for(char c : instructions){
            if(c=='G'){
                if(deg==0) y++;
                else if(deg==90) x--;
                else if(deg==180) y--;
                else if(deg==270) x++;
            }else if(c=='L'){
                deg = (deg+90)%360;
            }else{
                deg = (deg-90+360)%360;
            }
        }
        
        return deg!=0 || x==0 && y==0;
    }
};