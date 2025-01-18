""" Applying TAX """
prices = [1.09, 23.56, 57.84, 4.56, 6.78]
TAX_RATE = 8


def get_price_with_tax(prices, tax):
    return map(lambda p: p * (1 + tax / 100), prices)


final_prices = get_price_with_tax(prices, TAX_RATE)
final_prices = list(final_prices)
print("Applying TAX")
print(f"\tPrices: {prices}")
print(f"\tPrices with tax ({TAX_RATE}%): {final_prices}\n")

""" Applying DISCOUNT """
prices = [100, 200, 300, 400, 500]
DISCOUNT_RATE = 15


def get_price_with_discount(prices, discount):
    return map(lambda p: p * (1 - discount / 100), prices)


final_prices = get_price_with_discount(prices, DISCOUNT_RATE)
final_prices = list(final_prices)
print("Applying DISCOUNT")
print(f"\tPrices: {prices}")
print(f"\tPrices with discount ({DISCOUNT_RATE}%): {final_prices}\n")
