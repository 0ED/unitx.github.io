import decimal
decimal.getcontext().prec = 20001
x,e,two = decimal.Decimal(0.1), decimal.Decimal(+0), decimal.Decimal(2.0)
while True:
	b = x - (x * x - two) / (two * x)
	if b-e <= x and x <= b+e: break
	else: x = b
print x
