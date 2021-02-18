#include <iostream>
using namespace std;
int ans[20000];
int n, a, b;
int k[230];
void dfs(int cur, int dep)
{
    if (ans[cur] != -1 && dep > ans[cur])
        return;
    ans[cur] = dep;
    int t = cur + k[cur];
    if (t <= n)
        dfs(t, dep + 1);
    t = cur - k[cur];
    if (t > 0)
        dfs(t, dep + 1);
}
int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        ans[i] = -1;
    }
    ans[a] = 0;
    dfs(a, 0);
    cout << ans[b] << endl;
    return 0;
}
