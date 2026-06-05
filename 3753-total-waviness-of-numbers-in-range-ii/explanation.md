### **1. The General Strategy (Digit DP)**

* **The Range Trick:** To find an answer for a range `[L, R]`, calculate `count(R) - count(L - 1)`. This reduces the problem to "how many waves exist in all numbers from `1` to `X`".
* **Left-to-Right Construction:** We build the numbers digit by digit, starting from the most significant digit (leftmost) down to the least significant (rightmost).

---

### **2. The DP State Breakdown**

The memoization table `dp[pos][sum][prev2][prev][small][nz]` captures exactly where we are and what choices we have left:

* **`pos`**: The current digit index we are filling.
* **`sum`**: The total "waviness" (peaks + valleys) accumulated so far.
* **`prev2`** & **`prev`**: The two most recently placed digits. We need a window of 3 digits to identify a wave. *(Note: `10` is used as a dummy value meaning "uninitialized").*
* **`small` (Tight Bound Flag)**:
* `0` (False): Our prefix exactly matches the upper bound number so far. Our next digit **must not exceed** the actual digit `d[pos]`.
* `1` (True): We previously placed a digit smaller than the upper bound. The number is strictly smaller, so we are free to use **any digit `0-9`**.


* **`nz` (Non-Zero Flag)**:
* Tracks if our number has actually started. This is crucial so we don't accidentally count leading zeros as part of a wave (e.g., treating `005` as a wave, when it's really just `5`).



---

### **3. The Core Logic (Transitions)**

When we test placing a new digit `i` from `0` to `lim`:

* **Ignoring Leading Zeros:** If `nz` is false and we place a `0`, we haven't started the number yet. We pass `prev2 = 10` and `prev = 10` into the next recursive call.
* **Detecting a Wave:** If the number has started (`nz = true`), and we have at least two prior digits (`prev2 != 10` and `prev != 10`), we check the current window of three: `[prev2, prev, i]`.
* **Peak:** `prev2 < prev` AND `prev > i`
* **Valley:** `prev2 > prev` AND `prev < i`
* If either condition is met, we increment `nsum` by `1` for the next state.


* **Shifting the Window:** For the next recursive step, the old `prev` becomes the new `prev2`, and the current digit `i` becomes the new `prev`.

---

### **4. Memoization (DP)**

Digit DP relies on overlapping subproblems. If you are building a 10-digit number, the prefixes `132` and `798` both leave you at `pos = 3`, with `sum = 1`, and the exact same "wave" shape at the end (a drop). Instead of calculating the remaining 7 digits twice, the `dp` array stores the answer the first time and returns it in `O(1)` the next.
