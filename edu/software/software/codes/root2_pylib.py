import decimal
decimal.getcontext().prec = 20001
decimal.Decimal(2) ** decimal.Decimal(0.5)
