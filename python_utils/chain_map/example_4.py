from collections import ChainMap

fruits_prices = {"apple": 0.80, "grape": 0.40, "orange": 0.50}
veggies_prices = {"tomato": 1.20, "pepper": 1.30, "onion": 1.25}
prices = ChainMap(fruits_prices, veggies_prices)

order = {"apple": 4, "tomato": 8, "orange": 4}

for product, units in order.items():
    price = prices[product]
    subtotal = units * price
    print(f"{product:6}: ${price:.2f} × {units} = ${subtotal:.2f}")

# apple : $0.80 × 4 = $3.20
# tomato: $1.20 × 8 = $9.60
# orange: $0.50 × 4 = $2.00
