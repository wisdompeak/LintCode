class Solution {
public:
    /**
     * @param b: 
     * @param c: 
     * @param p: 
     * @return: return the a
     */
    double lotteryDraw(int b, int c, int p) 
    {
        double left = 0;
        double right = 100;
        while (abs(left-right) > 1e-6)
        {
            double a = (left+right)/2.0;
            double e = helper(a, b, c);

            if (e < 1 / (p * 0.01))
                right = a;
            else
                left = a;
        }
        return left;
    }
    
    double helper(double a, int b, double c)
    {
        int count = 1;
        double p_unluck = 1;
        double p_luck;
        double e = 0;
        
        while (1)
        {
            if (count < b)
                p_luck = a/100;
            else
                p_luck = (a+c*(count-b+1)*1.0)/100.0;
                
            p_luck = min(p_luck, 1.0);
            
            e += count * p_unluck * p_luck;
            
            if (p_luck>=1) 
                return e;
            
            p_unluck = p_unluck * (1-p_luck);
            count++;
        }
        
        return -1;
    }
};
