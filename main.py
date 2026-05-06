# A simple tool to calculate final grades based on 25-50-25 weightage as provided by CHED/DepEd.

print("--- Grade Calculator ---")

# Getting user inputs
written = float(input("Enter Written Work average (25%): "))
performance = float(input("Enter Performance Task average (50%): "))
exam = float(input("Enter Exam score (25%): "))

# Calculating the weighted components
written_component = written * 0.25
performance_component = performance * 0.50
exam_component = exam * 0.25

# Final Calculation
final_grade = written_component + performance_component + exam_component

print("--------------------------------")
print(f"Final Weighted Grade: {final_grade:.2f}")

# Pass/Fail Check
if final_grade >= 75:
    print("Status: PASSED")
else:
    print("Status: BELOW PASSING")
