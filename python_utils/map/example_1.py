prices = [1.09, 23.56, 57.84, 4.56, 6.78]
TAX_RATE = .08


def get_price_with_tax(price):
    return price * (1 + TAX_RATE)


final_prices = map(get_price_with_tax, prices)
final_prices = list(final_prices)
print(final_prices)
