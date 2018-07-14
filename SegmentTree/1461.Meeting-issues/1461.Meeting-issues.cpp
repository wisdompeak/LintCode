class Solution {
public:
    /**
     * @param meeting: The meetings
     * @param pause: The pause time of meetings
     * @param query: The query
     * @return: Return the answer of each query
     */     
    class segTree
    {
        public:
        int begin;
        int end;
        bool isOver;
        segTree* left;
        segTree* right;
        
        segTree(int a, int b)
        {
            begin = a;
            end = b;
            isOver = false;
            left = NULL;
            right = NULL;
        }
        
        ~segTree()
        {
            if (left!=NULL) delete left;
            if (right!=NULL) delete right;
        }
        
        void split()
        {
            if (end-begin<=1) return;
            int mid = (end-begin)/2+begin;
            left = new segTree(begin,mid);
            right = new segTree(mid,end);
        }
        
        void add(int a, int b)
        {
            cout<<begin<<" "<<end<<endl;
            if (isOver) return;
            if (begin >= b || end <= a) return;
		    if (begin >= a && end <= b) 
		    {
			    isOver = true;
			    return;
		    }
		    if (left==NULL || right==NULL)
		        this->split();
		    if (left != NULL) left->add(a, b);
		    if (right != NULL) right->add(a, b);
        }
        
        int getOverLength() 
        {
		    if (isOver)
			    return end - begin;
		    int n = 0;
		    if (left != NULL) 
		        n += left->getOverLength();
		    if (right != NULL) 
			    n += right->getOverLength();
			return n;
		}
    };
    
    void FindRanges(segTree* root, vector<pair<int,int>>& ranges)
    {
        if (root==NULL) return;
        //cout<<root->begin<<" "<<root->end<<endl;
        if (root->isOver) 
        {
            ranges.push_back({root->begin,root->end});
            return;
        }
        FindRanges(root->left,ranges);
        FindRanges(root->right,ranges);
    }
    
    
     
    vector<int> getQuery(vector<vector<int>> &meeting, vector<vector<int>> &pause, vector<int> &query) 
    {
        vector<pair<int,int>>Set;
        unordered_map<int,vector<int>>MeetingPause;
        for (int i=0; i<pause.size(); i++)
            MeetingPause[pause[i][0]].push_back(i);
        
        for (int i=0; i<meeting.size(); i++)
        {
            segTree* root = new segTree(meeting[i][1],meeting[i][2]+1);
            //root->split();
            
            for (int j: MeetingPause[meeting[i][0]])  
                root->add(pause[j][1],pause[j][2]+1);
            
            vector<pair<int,int>> pauseRanges;
            
            FindRanges(root,pauseRanges);
            
            /*
            for (int i=0; i<pauseRanges.size(); i++)
                cout<<pauseRanges[i].first<<"->"<<pauseRanges[i].second<<" ";
            cout<<endl;
            */
       
            vector<pair<int,int>> runRanges;
            
            if (pauseRanges.size()==0)
                runRanges.push_back({root->begin,root->end});
            else
            {
                int start = root->begin;
                int end = pauseRanges[0].first;
                if (start<end)
                    runRanges.push_back({start,end});
                    
                for (int i=0; i<int(pauseRanges.size()-1); i++)
                {
                    start = pauseRanges[i].second;
                    end = pauseRanges[i+1].first;
                    if (start<end)
                        runRanges.push_back({start,end});
                }
                
                start = pauseRanges.back().second;
                end = root->end;
                if (start<end)
                    runRanges.push_back({start,end});
            }
            

            /*
            for (int i=0; i<runRanges.size(); i++)
                cout<<runRanges[i].first<<"->"<<runRanges[i].second<<" ";
            cout<<endl;
            */
            
            for (int i=0; i<runRanges.size(); i++)
            {
                Set.push_back({runRanges[i].first,1});
                Set.push_back({runRanges[i].second,-1});
            }
            
            delete root;
            
        }
        
        sort(Set.begin(),Set.end());

        map<int,int>Map;
        int count=0;
        
        for (auto a:Set)
        {
            if (a.second==1)
                count+=1;
            else
                count-=1;
            
            Map[a.first] = count;
        }
        

        vector<int>result;
        for (int i=0; i<query.size(); i++)
        {
            auto it = Map.upper_bound(query[i]);
            if (it==Map.begin())
                result.push_back(0);
            else
            {
                it = prev(it,1);
                result.push_back(it->second);
            }
            
        }
        
        return result;
        
    }
};
