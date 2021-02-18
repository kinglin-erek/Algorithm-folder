#include <iostream>
#include <stack>
using namespace std;
int ans[20000];
int n, a, b;
int k[230];
struct node
{
    int cur, dep;
};
stack<node> S;
int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        ans[i] = -1;
    }

    ans[a] = 0;
    node t;
    t.cur = a;
    t.dep = 0;
    S.push(t);
    while (!S.empty())
    {
        t = S.top();
        S.pop();
        if (ans[t.cur] != -1 && t.dep > ans[t.cur])
            continue;
        ans[t.cur] = t.dep;
        int temp = t.cur + k[t.cur];
        if (temp <= n)
        {
            node newT;
            newT.cur = temp;
            newT.dep = t.dep + 1;
            S.push(newT);
        }
        temp = t.cur - k[t.cur];
        if (temp > 0)
        {
            node newT;
            newT.cur = temp;
            newT.dep = t.dep + 1;
            S.push(newT);
        }
    }
    cout << ans[b] << endl;
    return 0;
}