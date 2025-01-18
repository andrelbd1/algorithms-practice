sales = [100, 200, 50, 300, 150]
threshold = 150


def filter_high_sales(sales, threshold):
    """Filter sales greater than the threshold"""
    return filter(lambda s: s > threshold, sales)


sales_filtered = filter_high_sales(sales, threshold)
sales_filtered = list(sales_filtered)
print("Applying filter")
print(f"\tSales: {sales}")
print(f"\tSales with threshold ({threshold}): {sales_filtered}\n")
