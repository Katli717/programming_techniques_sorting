import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

df = pd.read_csv('sorting_times.csv')
df.sort_values(['Size'], inplace=True)

fig, axs = plt.subplots(2, 2, figsize=(15, 10))

axs[0][0].plot(df['Size'], df['SelectionSort'], label='Selection Sort', marker='o')
axs[0][0].plot(df['Size'], df['StdSort'], label='std::sort', marker='o')
axs[0][0].set_title('Сравнение Selection Sort и std::sort')
axs[0][0].set_xlabel('Size')
axs[0][0].set_ylabel('Time (µs)')
axs[0][0].legend()
axs[0][0].grid()

axs[1][0].plot(df['Size'], df['InsertionSort'], label='Insertion Sort', marker='o')
axs[1][0].plot(df['Size'], df['StdSort'], label='std::sort', marker='o')
axs[1][0].set_title('Сравнение Insertion Sort и std::sort')
axs[1][0].set_xlabel('Size')
axs[1][0].set_ylabel('Time (µs)')
axs[1][0].legend()
axs[1][0].grid()

axs[0][1].plot(df['Size'], df['HeapSort'], label='Heap Sort', marker='o')
axs[0][1].plot(df['Size'], df['StdSort'], label='std::sort', marker='o')
axs[0][1].set_title('Сравнение Heap Sort и std::sort')
axs[0][1].set_xlabel('Size')
axs[0][1].set_ylabel('Time (µs)')
axs[0][1].legend()
axs[0][1].grid()

axs[1][1].plot(df['Size'], df['SelectionSort'], label='Selection Sort', marker='o')
axs[1][1].plot(df['Size'], df['InsertionSort'], label='Insertion Sort', marker='o')
axs[1][1].plot(df['Size'], df['HeapSort'], label='Heap Sort', marker='o')
axs[1][1].plot(df['Size'], df['StdSort'], label='std::sort', marker='o')
axs[1][1].set_title('Все алгоритмы')
axs[1][1].set_xlabel('Size')
axs[1][1].set_ylabel('Time (µs)')
axs[1][1].legend()
axs[1][1].grid()

plt.tight_layout()
plt.savefig("comparison_charts.png")
