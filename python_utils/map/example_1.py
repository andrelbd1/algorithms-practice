""" Applying TAX """
def get_price_with_tax(prices, tax):
    return map(lambda p: p * (1 + tax / 100), prices)

prices = [1.09, 23.56, 57.84, 4.56, 6.78]
TAX_RATE = 8
final_prices = get_price_with_tax(prices, TAX_RATE)
final_prices = list(final_prices)
print("Applying TAX")
print(f"\tPrices: {prices}")  # [1.09, 23.56, 57.84, 4.56, 6.78]
print(f"\tPrices with tax ({TAX_RATE}%): {final_prices}\n")  # (8%): [1.1772000000000002, 25.4448, 62.467200000000005, 4.9248, 7.322400000000001]


""" Applying DISCOUNT """
def get_price_with_discount(prices, discount):
    return map(lambda p: p * (1 - discount / 100), prices)

prices = [100, 200, 300, 400, 500]
DISCOUNT_RATE = 15
final_prices = get_price_with_discount(prices, DISCOUNT_RATE)
final_prices = list(final_prices)
print("Applying DISCOUNT")
print(f"\tPrices: {prices}")  # [100, 200, 300, 400, 500]
print(f"\tPrices with discount ({DISCOUNT_RATE}%): {final_prices}\n")  # (15%): [85.0, 170.0, 255.0, 340.0, 425.0]
