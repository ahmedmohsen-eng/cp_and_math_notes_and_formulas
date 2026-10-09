/*
ordered_set<T>:
    Stores unique values in ascending order using std::less<T>.

ordered_multiset<T>:
    Stores duplicate values using {value, unique_id} pairs.
    Each unique_id must be different, and the ordering is ascending
    by value, then by unique_id.

For ordered_set<int> s:

    count(x < k)  = s.order_of_key(k);
    count(x >= k) = s.size() - s.order_of_key(k);

    count(x <= k) = s.order_of_key(k + 1);
    count(x > k)  = s.size() - s.order_of_key(k + 1);

    count(x == k) = s.order_of_key(k + 1) - s.order_of_key(k);

For pair-based ordered_multiset<int> s, assuming all IDs are nonnegative:

    count(x < k)  = s.order_of_key({k, 0});
    count(x >= k) = s.size() - s.order_of_key({k, 0});

    For <=, >, and ==, use the same rank-difference idea,
    with a key that sorts after every pair whose value is k.

order_of_key(key):
    Counts elements strictly before key according to the comparator.

find_by_order(i):
    Returns an iterator to the element at zero-based index i.

All these PBDS operations take O(log n).

Note: The k + 1 formulas assume integer keys and can overflow
when k == LLONG_MAX.
*/
