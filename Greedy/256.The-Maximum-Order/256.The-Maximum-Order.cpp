class Solution {
public:
    /**
     * the maximum units of creamer the manager can order without waste
     * @param onHand int整型vector the expiry days of m units of creamer already in stock
     * @param supplier int整型vector the expiry days of n units of creamer available for order
     * @param demand int整型 the maximum units of creamer employees will uses daily
     * @return int整型
     */
    int stockLounge(vector<int>& onHand, vector<int>& supplier, int demand) {
        sort(onHand.begin(), onHand.end());
        sort(supplier.begin(), supplier.end());
        int maxDay = max(onHand.back(), supplier.back());

        vector<pair<int,int>>need;
        int i = 0;
        for (int d=0; d<=maxDay; d++)
        {
            need.push_back({d, demand});

            if (i<onHand.size() && onHand[i]<d)
                return -1;
            while (i<onHand.size() && onHand[i]==d && need.size()>0)
            {
                need.back().second-=1;
                i++;
                if (need.back().second==0)
                    need.pop_back();
            }
        }

        i = 0;
        int ret = 0;
        for (auto x: need)
        {
            int d = x.first;
            int n = x.second;
            while (i<supplier.size() && supplier[i]<d)
                i++;
            while (n>0 && i<supplier.size())
            {       
                n -= 1;
                ret += 1;
                i++;
            }
        }

        return ret;
    }
};
