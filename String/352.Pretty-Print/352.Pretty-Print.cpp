class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * return the result of pretty print.
     * @param text string字符串vector<vector<>> the text to print
     * @param width int整型 the width of the window
     * @return string字符串vector
     */
    vector<string> prettyPrint(vector<vector<string> >& text, int width) 
    {
        vector<string>rets;
        for (auto sentence: text)
        {
            int count = 0;
            string line;
            for (auto word: sentence)
            {
                if (count==0)
                {
                    count+=word.size();
                    line+=word;
                    continue;                    
                }
                
                if (count+1+word.size()<=width)
                {
                    line += " " + word;
                    count += 1 + word.size();
                }
                else
                {                    
                    while (line.size()<width)
                        line += " ";
                    rets.push_back(line);
                    line = word;                    
                    count = word.size();
                }
            }
            if (line!="")
            {
                while (line.size()<width)
                    line += " ";
                rets.push_back(line);
            }
                
        }
        for (int i=0; i<rets.size(); i++)
        {
            rets[i] = "*" + rets[i] + "*";
        }
        string head;
        for (int i=0; i<width+2; i++)
            head += "*";
        rets.insert(rets.begin(),head);
        rets.push_back(head);
        return rets;
    }
};
