#! /usr/bin/env python
# -*- coding:utf-8 -*-

"""
√2を小数点以下2万桁，「ニュートン法」と「Pythonの内部処理」で計算し，正答率を出力するプログラム．計算スピードは非常に遅いのでログを取り，計算を一度すれば，次からはログから結果を取り出す．もし，再計算したい場合はカレントディレクトリのログファイルを消去すれば，再計算できる．MacBookで試すなら実行時間が「ニュートン法」と「Pythonの内部処理」の両方を含めて，約5分間 計算時間がかかるので，プログラムを読んで適切にわけると良い．ちなみに二度目以降の計算時間は，ログから出力するだけなので，すぐに出力されます．

【Pythonの2^0.5】
real	5m14.328s
user	5m14.124s
sys	0m0.158s
【ニュートン法】
real	0m3.990s
user	0m3.969s
sys	0m0.015s

この実験結果は，iMac(プロセッサ2.66GHz Intel Core i5, メモリ8GB)による結果であり，ニュートン法の方が明らかに早く見える．また，ニュートン法はwhileループのループ回数から，オーダーを知ることができる．計算した結果はニュートン法はO(19)だった．
"""

import sys
import os 
from decimal import getcontext
from decimal import Decimal


def f(x): return x * x - Decimal(2.0)
def ff(x): return 2 * x

def nyuton():
	x = Decimal(0.1)
	e = Decimal(+0)
	count = 0
	while True:
		b = x - f(x)/ff(x)
		if b-e <= x and x <= b+e:
			print "ニュートン法: O(%s)" % count
			return x
		else:
			x = b
		count+=1

def pysqrt():
	return Decimal(2) ** Decimal(0.5)

def logger(func,filename):
	if filename in os.listdir("."):
		with open(filename,'r') as a_file:
			return a_file.read()
	else:
		ans = func()
		with open(filename,'w') as a_file:
			a_file.write(str(ans))
		return ans

def main():
	getcontext().prec = 20001
	ans1 = logger(pysqrt,"pysqrt.log")
	ans2 = logger(nyuton,"nyuton.log")
	count = 0
	for l,r in zip(str(ans1),str(ans2)):
		if l == r:
			count+=1
	print "一致した桁数: %s" % count
	print "全体の桁数: %s" % len(str(ans1))
	print "正解率: %s%%" % (count * 100 / float(len(str(ans1))))

if __name__ == '__main__':
	sys.exit(main())

