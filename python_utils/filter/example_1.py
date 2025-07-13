sales = [100, 200, 50, 300, 150]
threshold = 150

sales_filtered = filter(lambda s: s > threshold, sales)
print("Applying filter")
print(f"\tSales: {sales}")  # [100, 200, 50, 300, 150]
print(f"\tSales with threshold ({threshold}): {list(sales_filtered)}\n")  # (150): [200, 300]
