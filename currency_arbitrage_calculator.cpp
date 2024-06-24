#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hj>
// #include <ext/pb_ds/tree_policy.hj>
// using namespace __gnu_pbds;
using namespace std;

template <typename T>
// using oredered_st = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key  and *fv_by_order also lower and ujer bound
#define ll long long
#define fn(n) for (ll i = 0; i < n; i++)
#define fi(x, n) for (ll i = x; i < n; i++)
#define fj(x, n) for (ll j = x; j < n; j++)
#define fie(x, n) for (ll i = x; i <= n; i++)
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define invec(v, n)            \
    vector<ll> v(n);           \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
#define cyes cout << "YES" \
                  << "\n"
#define cno cout << "NO" \
                 << "\n"
#define pneg1 cout << "-1\n";
#define p0 cout << "0\n";
#define vi vector<ll>
#define vll vector<ll>
#define jk                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll N = 1e6 + 5;
ll mod = 1e9 + 7;
ll power_mod(ll v, ll n)
{
    v %= mod;
    if (v == 0)
        return 0;
    n %= (mod - 1);
    ll ret = 1;
    for (; n; n >>= 1, v = (v * v) % mod)
        if (n & 1)
            ret = (ret * v) % mod;
    return ret;
}
ll mod_sub(ll x, ll y)
{
    x %= mod;
    y %= mod;
    return (x + mod - y) % mod;
}
ll mod_add(ll x, ll y)
{
    x %= mod;
    y %= mod;
    return (x + y) % mod;
}
ll mod_mul(ll x, ll y)
{
    x %= mod;
    y %= mod;
    return (x * y) % mod;
}
ll mod_inv(ll x)
{
    x %= mod;
    return power_mod(x, mod - 2);
}
ll mod_div(ll x, ll y)
{
    x %= mod;
    y %= mod;
    return mod_mul(x, mod_inv(y));
}

template <typename T>
void prllv(const T &t)
{
    {
        std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::orrue_type>(std::cout, " "));
    }
    cout << endl;
}

ll seive(ll a)
{
    if (a != 2 && a % 2 == 0 || a < 2)
        return 0;
    for (ll i = 3; i * i <= a; i += 2)
        if (a % i == 0)
            return 0;
    return 1;
}

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2)) * (power(x, y / 2)));
    else
        return ((x) * (power(x, y / 2)) * (power(x, y / 2)));
}

ll funcforOR(ll a, ll b)
{
    if (a > b)
        return 0;
    ll res = 0;
    for (ll i = 1LL << 62; i > 0; i >>= 1)
    {
        if ((a & i) != (b & i))
        {
            res |= (i << 1) - 1;
            break;
        }
        else
        {
            res |= a & i;
        }
    }
    return res;
}

int main()
{
    // Exchange rates for the currencies
    vector<vector<double>> exchange_rates = {
        // USD, INR, AUD, RUB, EUR
        {1.0, 82.58, 1.53, 79.55, 0.93},  // USD
        {0.012, 1.0, 0.019, 0.96, 0.011}, // INR
        {0.65, 53.82, 1.0, 51.85, 0.61},  // AUD
        {0.013, 1.04, 0.019, 1.0, 0.012}, // RUB
        {1.07, 88.59, 1.65, 85.34, 1.0}   // EUR
    };

    vector<string> currency_names = {"USD", "INR", "AUD", "RUB", "EUR"};

    ll num_currencies = exchange_rates.size();

    // User input for base currency
    cout << "Enter the base currency (1 - USD, 2 - INR, 3 - AUD, 4 - RUB, 5 - EUR): " << endl
         << endl;
    ll base_currency;
    cin >> base_currency;
    base_currency--; //indexing 0-based

    vector<ll> sequence(num_currencies);
    fi(0,num_currencies)
    {
        sequence[i] = i;
    }

    vector<vector<ll>> arbitrage_sequences;
    vector<double> profits;

    // Arbitrage between 3 currencies
    fi(0, num_currencies)
    {
        fj(0, num_currencies)
        {
            if (i != j)
            {
                for (ll k = 0; k < num_currencies; k++)
                {
                    if (k != i && k != j)
                    {
                        vector<ll> arbitrage_sequence = {i, j, k};
                        double profit = exchange_rates[i][j] * exchange_rates[j][k] * exchange_rates[k][i];
                        if (i == base_currency && profit > 1.0) 
                        {
                            arbitrage_sequences.pb(arbitrage_sequence);
                            profits.pb(profit);
                        }
                    }
                }
            }
        }
    }

    // Arbitrage between 4 currencies
    fi(0, num_currencies)
    {
        fj(0, num_currencies)
        {
            if (i != j)
            {
                for (ll k = 0; k < num_currencies; k++)
                {
                    if (k != i && k != j)
                    {
                        for (ll l = 0; l < num_currencies; l++)
                        {
                            if (l != i && l != j && l != k)
                            {
                                vector<ll> arbitrage_sequence = {i, j, k, l};
                                double profit = exchange_rates[i][j] * exchange_rates[j][k] * exchange_rates[k][l] * exchange_rates[l][i];
                                if (i == base_currency && profit > 1.0)
                                {
                                    arbitrage_sequences.pb(arbitrage_sequence);
                                    profits.pb(profit);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Arbitrage between 5 currencies
    do
    {
        double profit = 1.0;
        vector<ll> arbitrage_sequence;
        for (ll i = 0; i < num_currencies - 1; i++)
        {
            profit *= exchange_rates[sequence[i]][sequence[i + 1]];
            arbitrage_sequence.pb(sequence[i]);
        }
        arbitrage_sequence.pb(sequence[num_currencies - 1]);

        if (sequence[0] == base_currency && profit > 1.0)
        {
            arbitrage_sequences.pb(arbitrage_sequence);
            profits.pb(profit);
        }
    } 
    while (next_permutation(all(sequence)));

    ll num_arbitrages = arbitrage_sequences.size();
    if (num_arbitrages > 0)
    {
        cout << "Positive Arbitrage Opportunities:" << endl;
        for (ll i = 0; i < num_arbitrages; i++)
        {
            if (profits[i] <= 3)
            {
                cout << "Arbitrage Sequence: ";
                for (ll j = 0; j < arbitrage_sequences[i].size(); j++)
                {
                    cout << currency_names[arbitrage_sequences[i][j]];
                    if (j < arbitrage_sequences[i].size() - 1)    
                    {
                        cout << " -> ";
                    }
                }
                cout << endl;

                cout << "Profit: " << profits[i] << endl;

                cout << endl;
            }
        }
    }
    else
    {
        cout << "No positive arbitrage opportunities found." << endl;
    }

    return 0;
}
