import pandas as pd
import matplotlib.pyplot as plt

data = {
    "Machine": ["M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9", "M10"],
    "Temperature": [25, 28, 31, 45, 27, 29, 42, 26, 30, 47],
    "Pressure": [100, 102, 98, 110, 101, 99, 108, 97, 103, 112],
    "Vibration": [2.1, 2.5, 2.8, 4.5, 2.3, 2.6, 4.2, 2.0, 2.7, 4.8]
}

df = pd.DataFrame(data)

print("INDUSTRIAL SENSOR DATA")
print(df)

print("\\nSTATISTICAL ANALYSIS")
print("Average Temperature:", df["Temperature"].mean())
print("Maximum Temperature:", df["Temperature"].max())
print("Minimum Temperature:", df["Temperature"].min())
print("Average Pressure:", df["Pressure"].mean())
print("Average Vibration:", df["Vibration"].mean())

threshold = 40
abnormal = df[df["Temperature"] > threshold]

print("\\nABNORMAL TEMPERATURE READINGS")
print(abnormal)

# Temperature graph
plt.figure(figsize=(8, 4))
plt.plot(df["Machine"], df["Temperature"], marker="o")
plt.axhline(y=threshold, linestyle="--", label="Temperature Limit")
plt.title("Industrial Machine Temperature Analysis")
plt.xlabel("Machine")
plt.ylabel("Temperature (°C)")
plt.legend()
plt.grid()
plt.tight_layout()
plt.show()

# Vibration graph
plt.figure(figsize=(8, 4))
plt.bar(df["Machine"], df["Vibration"])
plt.title("Industrial Machine Vibration Analysis")
plt.xlabel("Machine")
plt.ylabel("Vibration Level")
plt.grid(axis="y")
plt.tight_layout()
plt.show()
