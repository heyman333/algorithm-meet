#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
long long n, arr[100001];
long long histogram(){
    stack<long long> st;
    long long i,ret = 0;
    st.push(-1);
    for(i=0; i<n;i++){
        //������ ������� �ʰ�,  
        while(!st.empty()&&arr[i]<arr[st.top()]){
            int tmp = st.top(); st.pop();
            if(!st.empty())
                //left�� st.top
                //left-right-1 �ʺ�, ���� arr[tmp]�� ���簢�� ���� 
                ret = max(ret, arr[tmp]*(i-st.top()-1));
        }
        //�ʺ� �� ���ϰ� ���� ���ڸ� ���ÿ� ����.
        st.push(i); 
    }
    //������׷��� ������ ���ÿ� �־��µ��� �ȳ����ٸ�
    //���ÿ� �����ִ� ���ڵ鿡���� �ִ밪�� ���Ѵ�. 
    while(!st.empty()) {
        int tmp = st.top(); st.pop();
        if(!st.empty())
            ret = max(ret, arr[tmp]*(i-st.top()-1));
    }
    return ret;
}
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    printf("%lld\n",histogram());
    
}   