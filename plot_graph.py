from matplotlib import pyplot as plt

time_file = open("thread_results")
times = time_file.readlines()
actual_times = [] 
for item in times:
    actual_times.append(int(item.split("\n")[0]))

actual_times.sort()
print(actual_times)
plt.plot(range(len(actual_times)), actual_times)
plt.show()
