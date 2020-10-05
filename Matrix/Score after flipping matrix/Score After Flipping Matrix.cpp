class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int ans=0;
        
        int r=A.size();
        int c=A[0].size();
        //cout<<r<<"*"<<c;
        
        for(int i=0;i<r;i++)
        {
            int lc=0,rc=0;
            if(A[i][0]==0)
            for(int j=0;j<c;j++)
            {
                if(A[i][j]==0)
                {
                    A[i][j]=1;
                }
                else
                {
                    A[i][j]=0;
                }
            }
            
        }
        for(int j=0;j<c;j++)
        {
            int oc=0,zc=0;
            for(int i=0;i<r;i++)
            {
                if(A[i][j]==0) zc++;
                else oc++;
            }
            if(zc>oc)
            {
                for(int i=0;i<r;i++)
                {
                    if(A[i][j]==0) A[i][j]=1;
                    else A[i][j]=0;
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            int sum=0,pw=0;
            for(int j=c-1;j>=0;j--)
            {
                sum+=A[i][j]*int(pow(2,pw));
                pw++;
            }
            //cout<<sum<<" ";
            ans+=sum;
        }
        return ans;
    }
};
