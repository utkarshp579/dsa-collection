/*
    Competitive Programming Template
    Author: Utkarsh
    Rating: 1600+ Codeforces
*/

#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Constants
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;

// Macros
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
inline int sz(const auto& x) { return (int)x.size(); }
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define yes cout << 'YES
';
#define no cout << 'NO
';

// Debugging
#ifdef LOCAL
#include 'debug.h'
#else
#define debug(...) cerr << '[' << #__VA_ARGS__ << '] = ', dbg(__VA_ARGS__)
template <typename T, typename... Args> void dbg(T t, Args... args) {
    cerr << t << ' ';
    if constexpr (sizeof...(args) > 0) dbg(args...);
    else cerr << endl;
}
#endif

// Common Data Structures
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

// Power Function with Modulo
ll power(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// GCD and LCM
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Binary Search (Avoid Overflow)
int binary_search(vi &arr, int x) {
    int l = 0, r = sz(arr) - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        (arr[mid] < x) ? l = mid + 1 : r = mid - 1;
    }
    return -1;
}

// Graph Representation
vector<vi> adj(100005); // Resized to avoid runtime errors
void add_edge(int u, int v) {
    adj[u].pb(v);
    adj[v].pb(u);  // Remove for directed graph
}

// DFS & BFS
bitset<100005> visited;
void dfs(int node) {
    visited[node] = true;
    for (int v : adj[node]) {
        if (!visited[v]) dfs(v);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int v : adj[node]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// DSU (Disjoint Set Union)
struct DSU {
    vector<int> parent, size;
    DSU(int n) { parent.resize(n); size.resize(n, 1); iota(parent.begin(), parent.end(), 0); }
    int find(int v) { return parent[v] = (parent[v] == v ? v : find(parent[v])); } // Path Compression
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a; size[a] += size[b];
        }
    }
};

// Trie (Prefix Matching)
struct Trie {
    struct Node { unordered_map<char, Node*> children; bool end = false; };
    Node* root = new Node();
    void insert(string s) {
        Node* node = root;
        for (char c : s) {
            if (!node->children[c]) node->children[c] = new Node();
            node = node->children[c];
        }
        node->end = true;
    }
    bool search(string s) {
        Node* node = root;
        for (char c : s) {
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return node->end;
    }
};

// Main Function
int main() {
    fast_io();
    cout << 'Competitive Programming Template Loaded!';
    return 0;
}
