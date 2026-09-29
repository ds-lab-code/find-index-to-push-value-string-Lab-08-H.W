# Student Name Push Index

📌 Homework Requirement

এই homework-এ আমাদের একটি alphabetically sorted student name-এর array দেওয়া হয়েছে।

আমাদের কাজ হলো:

Array-তে কিছু student-এর নাম থাকবে।
User একটি নতুন student-এর নাম input দেবে।
নতুন নামটি alphabetical order ঠিক রাখার জন্য array-এর কোন index-এ push/insert করা উচিত, সেটি বের করতে হবে।
যদি input করা নামটি array-তে আগে থেকেই থাকে, তাহলে নতুন নামটি existing নামটির পরের index-এ যাবে।
যদি নতুন নামটি সব existing নামের পরে আসে, তাহলে তার index হবে 5।
সবশেষে শুধু সেই index number print করতে হবে।

আমাদের এখানে আসলে name-টি array-তে insert করতে হবে না। শুধু name-টি কোন index-এ insert করা উচিত, সেই index number বের করতে হবে।

📝 Example

ধরি আমাদের দেওয়া array হলো:

Index 0 → Abubokkor
Index 1 → Farjin
Index 2 → Rafit
Index 3 → Sazzad
Index 4 → Srabon

এখন user যদি input দেয়:

Ratul

তাহলে alphabetical order ঠিক রাখতে Ratul কোথায় বসবে?

Abubokkor
Farjin
Rafit
Ratul      ← নতুন নাম
Sazzad
Srabon

Ratul-এর আগে আছে Rafit এবং পরে আছে Sazzad।

তাই Ratul-এর insertion position হবে:

Index : 3

Program-এর output হবে:

Index : 3

## 💻 Given Array

আমাদের program-এ শুরুতে এই student names দেওয়া আছে:

```c
char names[5][20] = {
    "Abubokkor",
    "Farjin",
    "Rafit",
    "Sazzad",
    "Srabon"
};
```

Index অনুযায়ী array:

| Index | Name      |
| ----: | --------- |
|     0 | Abubokkor |
|     1 | Farjin    |
|     2 | Rafit     |
|     3 | Sazzad    |
|     4 | Srabon    |

নামগুলো alphabetical order-এ সাজানো আছে।

---

# 🔍 Code Explanation

## 1. Header Files

```c
#include <stdio.h>
#include<string.h>
```

এখানে দুইটি header file ব্যবহার করা হয়েছে।

### `stdio.h`

এটি ব্যবহার করা হয়েছে:

* `printf()`
* `scanf()`

এর জন্য।

### `string.h`

এটি ব্যবহার করা হয়েছে:

* `strcmp()`

function ব্যবহার করার জন্য।

`strcmp()` দুইটি string compare করতে সাহায্য করে।

---

## 2. Student Names Array

```c
char names[5][20] = {
    "Abubokkor",
    "Farjin",
    "Rafit",
    "Sazzad",
    "Srabon"
};
```

এখানে:

```text
5
```

মানে মোট ৫টি name রাখা যাবে।

আর:

```text
20
```

মানে প্রতিটি name-এর জন্য সর্বোচ্চ ১৯টি character + `\0` রাখা যাবে।

এটি একটি **2D character array**, যেটি আমরা সহজভাবে multiple string রাখার জন্য ব্যবহার করছি।

---

## 3. Input রাখার জন্য Array

```c
char item[20];
```

User যে নতুন student-এর নাম input দেবে, সেটি `item` variable-এর মধ্যে রাখা হবে।

যেমন user যদি লেখে:

```text
Ratul
```

তাহলে:

```text
item = "Ratul"
```

হবে।

---

## 4. Index Variable

```c
int index = 5;
```

এখানে শুরুতেই `index`-এর value `5` দেওয়া হয়েছে।

এর কারণ হলো:

আমাদের existing array-এর index হলো:

```text
0  1  2  3  4
```

যদি নতুন নামটি সব existing নামের পরে আসে, তাহলে সেটি array-এর শেষে যাবে।

সেক্ষেত্রে তার index হবে:

```text
5
```

### Example

যদি input হয়:

```text
Tanim
```

তাহলে:

```text
Abubokkor
Farjin
Rafit
Sazzad
Srabon
Tanim
```

`Tanim` সবার পরে আসবে।

তাই:

```text
Index : 5
```

---

## 5. User-এর কাছ থেকে Name নেওয়া

```c
printf("Enter Name to Push: ");
scanf("%s", item);
```

প্রথমে user-কে name দিতে বলা হচ্ছে।

তারপর `scanf()` দিয়ে name নেওয়া হচ্ছে এবং `item`-এর মধ্যে রাখা হচ্ছে।

Example:

```text
Enter Name to Push: Ratul
```

তখন:

```text
item = "Ratul"
```

---

# 🔄 6. Array-এর প্রতিটি Name Check করা

```c
for(int i=0; i<5; i++){
```

এই `for` loop array-এর প্রতিটি name একে একে check করবে।

Loop চলবে:

```text
i = 0
i = 1
i = 2
i = 3
i = 4
```

অর্থাৎ:

```text
Abubokkor
Farjin
Rafit
Sazzad
Srabon
```

প্রতিটি name-এর সাথে input করা name compare করা হবে।

---

# 🔤 7. `strcmp()` দিয়ে Name Compare করা

```c
if(strcmp(names[i], item) > 0){
    index = i;
    break;
}
```

এখানে `strcmp()` ব্যবহার করে দুইটি name compare করা হচ্ছে।

```c
strcmp(names[i], item)
```

এর অর্থ:

> `names[i]` এবং `item` compare করো।

যদি result `0`-এর বেশি হয়:

```c
strcmp(names[i], item) > 0
```

তাহলে `names[i]` alphabetically `item`-এর পরে আছে।

সেক্ষেত্রে নতুন name-এর insertion index হবে `i`।

তাই:

```c
index = i;
```

এবং:

```c
break;
```

দিয়ে loop বন্ধ করা হচ্ছে।

---

## 📝 Example: `Ratul`

ধরি input:

```text
Ratul
```

তখন comparison হবে:

```text
Abubokkor < Ratul
Farjin    < Ratul
Rafit     < Ratul
Sazzad    > Ratul
```

প্রথম যে name `Ratul`-এর পরে এসেছে সেটি হলো:

```text
Sazzad
```

এর index:

```text
3
```

তাই:

```c
index = 3;
```

হবে।

শেষে:

```text
Index : 3
```

print হবে।

---

# 🟰 8. যদি একই Name পাওয়া যায়

```c
else if(strcmp(names[i], item) == 0){
    index = i+1;
    break;
}
```

এখানে check করা হচ্ছে input করা name এবং array-এর current name একই কিনা।

`strcmp()` যদি:

```text
0
```

return করে, তাহলে দুইটি string একই।

### Example

Input:

```text
Rafit
```

Array:

```text
0 → Abubokkor
1 → Farjin
2 → Rafit
3 → Sazzad
4 → Srabon
```

`Rafit` পাওয়া গেছে:

```text
index = 2
```

কিন্তু homework-এর rule অনুযায়ী নতুন `Rafit`-কে existing `Rafit`-এর **পরে** push করা হবে।

তাই:

```c
index = i + 1;
```

অর্থাৎ:

```text
2 + 1 = 3
```

তাই output:

```text
Index : 3
```

হবে।

---

# 🛑 9. `break` কেন ব্যবহার করা হয়েছে?

```c
break;
```

এর কাজ হলো loop সঙ্গে সঙ্গে বন্ধ করে দেওয়া।

যখন আমরা প্রথম suitable index পেয়ে যাই, তখন আর বাকি names check করার প্রয়োজন নেই।

তাই `break` ব্যবহার করে loop বন্ধ করা হয়েছে।

---

# 🖨️ 10. Index Print করা

```c
printf("Index : %d", index);
```

সবশেষে calculated index print করা হচ্ছে।

Homework-এর requirement অনুযায়ী আমাদের শুধু index number-ই দরকার।

---

# 🧪 Example Outputs

## Example 1

Input:

```text
Enter Name to Push: Ratul
```

Output:

```text
Index : 3
```

কারণ `Ratul` আসবে `Rafit` এবং `Sazzad`-এর মধ্যে।

---

## Example 2

Input:

```text
Enter Name to Push: Farjin
```

`Farjin` already আছে index `1`-এ।

নতুন `Farjin` তার পরে যাবে।

তাই:

```text
Index : 2
```

---

## Example 3

Input:

```text
Enter Name to Push: Tanim
```

`Tanim` সব existing name-এর পরে আসবে।

তাই:

```text
Index : 5
```

---

## Example 4

Input:

```text
Enter Name to Push: Araf
```

`Araf` প্রথম name `Abubokkor`-এর পরে এবং `Farjin`-এর আগে আসবে।

তাই:

```text
Index : 1
```

---

# 🧠 Important Concept: `strcmp()`

এই homework-এর সবচেয়ে গুরুত্বপূর্ণ অংশ হলো:

```c
strcmp()
```

`strcmp()` দুইটি string compare করে।

সাধারণভাবে:

| `strcmp()` Result | Meaning          |
| ----------------: | ---------------- |
|             `< 0` | প্রথম string ছোট |
|            `== 0` | দুই string একই   |
|             `> 0` | প্রথম string বড়  |

যেমন:

```c
strcmp("Rafit", "Sazzad")
```

এর result `0`-এর কম হবে, কারণ `Rafit` alphabetical order-এ `Sazzad`-এর আগে।

আর:

```c
strcmp("Sazzad", "Ratul")
```

এর result `0`-এর বেশি হবে, কারণ `Sazzad` alphabetical order-এ `Ratul`-এর পরে।

---

I Hope this will be helpful for you!


