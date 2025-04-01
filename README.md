# push\_swap - 42 School

### 🏆 Score: **125/100** (+25 for bonus)

## 📚 About the Project

**push\_swap** is an algorithmic project that requires sorting a list of random numbers using two stacks (**A** and **B**) and a limited set of operations. The goal is **not** to find the most time-efficient sorting algorithm but rather the sorting method that achieves the correct order using the **fewest possible operations**

### 🧠 My Approach

1. **Determine the final positions** of the numbers in the sorted order using a simple position assignment method
2. **Use "k-sort"** to efficiently move elements into their correct positions with minimal operations

### 🔍 What is "k-sort"?

The name "k-sort" comes from the visual pattern that forms in Stack B during the sorting process. When numbers are positioned, Stack B resembles the letter 'K': larger numbers collect at the top and bottom, while smaller numbers gather in the middle

#### How the Algorithm Works:

- All numbers start in **Stack A**, divided into **chunks** based on their final sorted position (e.g., in 100 numbers, chunks of 20)
- The smallest chunk (e.g., the 20 smallest numbers) is moved first, followed by the next smallest, and so on
- When moving a chunk:
  - Numbers aren't transferred in sorted order but in the order they appear in Stack A to minimize operations
  - Stack A is rotated (**ra / rra**) to bring the target numbers to the top for pushing
- Numbers are placed in **Stack B strategically**:
  - Some go to the **top**
  - Some go to the **bottom**
  - This forms the **'K' shape**: big numbers at the top and bottom, small numbers in the middle
- Once all numbers are in **Stack B**, they are pushed back to **Stack A** in sorted order:
  - The largest value near the top or bottom of Stack B is identified
  - Depending on its position, **rb / rrb** is used to bring it to the top before pushing it back to Stack A
- This process repeats until Stack B is empty, leaving **Stack A fully sorted**



### 📚 What I Learned
- **Stack Operations**: Efficiently manipulating data using basic operations like push, swap, and rotate
- **Move Optimization**: Focusing on finding the most efficient sequence of operations to minimize the total number of moves
- **Problem-Specific Algorithm Development**: Tailoring the sorting approach to fit the specific constraints and challenges of the push_swap project



## 🚀 Usage

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/t-ecker/42-push_swap.git
cd push_swap
```
### 2️⃣ Compile the Program
```bash
make && make bonus
```

### 3️⃣ Run the Program

```bash
./push_swap "2 1 3 6 5 8"
```

This outputs the sequence of operations to sort the numbers

### 4️⃣ Testing with the Checker (Bonus of this project)

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

If the output is correct, the checker will print:

```
OK
```

Otherwise, it will print:

```
KO
```

To count the number of operations used:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### 5️⃣ Running the Visualizer (only availiable for x86_64 architecture)

A visualizer to help understanding how the sorting process works step by step

📌 **Note:** The visualizer is not my creation. Full credit goes to its original developer, whose repository can be found [here](https://github.com/o-reo/push_swap_visualizer)

To compile and run the visualizer:

```bash
make visualizer
```



## 📊 Performance Benchmark

Here are the amount of operation needed for specific sizes of numbers

| **Size**    | **Operations** |
| ----------- | ------------ |
| 5 numbers   | \~5-10       |
| 100 numbers | \~560-630    |
| 500 numbers | \~5000-5400  |



## 🏁 Conclusion

**push\_swap** is a challenging algorithmic problem that prioritizes move optimization over pure time efficiency
