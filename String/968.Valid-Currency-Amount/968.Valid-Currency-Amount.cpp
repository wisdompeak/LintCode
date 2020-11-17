class Solution {
public:
    /**
     * @param currency: a string represents a valid or invalid currency amount
     * @return: return whether the given string is a valid currency
     */
    bool validCurrencyAmount(string &currency) 
    {
        int n = currency.size();        

        // 如果第一个字符是负号
        if (currency[0]=='-')
        {
            string s = currency.substr(1);            
            return check1(s);
        }

        // 如果最外层是一对括号
        if (currency[0]=='(')
        {
            if (currency.back()!=')')
                return false;
            string s = currency.substr(1, n-2);
            return check1(s);
        }

        // 如果没有负号或者括号
        string s = currency;
        return check1(s);
    }
    
    bool check1(string s)
    {
    	// 第一个字符必须是货币符号
        if (s[0]!='D'&&s[0]!='E'&&s[0]!='Y')
            return false;

        // 如果是日元，不允许有小数点
        if (s[0]=='Y')
        {
            for (int i=1; i<s.size(); i++)
                if (s[i]=='.') return false;
        }
    
    	// 切掉货币符号再查验    
        return check2(s.substr(1));
    }
    
    bool check2(string s)   // 查验小数点和小数部分
    {
        
        int n = s.size();
        // 数字为空？false
        if (n==0) return false;
        
        // 有非法字符？false
        for (int i=0; i<n; i++)
        {
            if (s[i]!='.' && s[i]!=',' && !isdigit(s[i]))
                return false;
        }
        
        // 除了0或者0.xx之外，有leading zero? false
        if (s[0]=='0' && (s!="0" && s[1]!='.'))
            return false;
            
        int flag = 0;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='.')
                flag++;
        }
        
        // 有两个小数点？false
        if (flag>=2) return false;
        // 有一个小数点但是长得不象xxxx.xx？false
        if (flag==1)
        {
            if (n<4) return false;
            if (s[n-3]!='.') return false;
            if (!isdigit(s[n-1]) || !isdigit(s[n-2])) return false;
            s = s.substr(0, n-3);
        }
        
        // 切掉小数部分再查验
        return check3(s);
    }
    

    bool check3(string s)  // 查验分隔符和整数部分
    {
        
        if (!isdigit(s[0])) return false;
        int n = s.size();
        
        int flag = 0;
        for (int i=0; i<n; i++)
        {
            if (s[i]==',')
            {
                flag = 1;
                break;
            }
        }
        
        // 没有分隔符，返回true
        if (flag==0) return true;
        
        // 分隔符位置不对，返回false
        for (int i=n-1; i>=0; i--)
        {
            if ((n-i)%4!=0 && s[i]==',')
                return false;
            if ((n-i)%4==0 && s[i]!=',')
                return false;
        }
        return true;
    }
};
