require 'bigdecimal'
require 'bigdecimal/util'

=begin
a. 非負整数 n を受け取り、2のn乗 を計算する。
=end
def a(n)
	begin
		n = n.to_i.abs
		result = 1
		while n > 0 do
			result = result * 2
			n -= 1
			puts n
		end
		return result
	rescue => e
		return e.message
	end
end

=begin
b. 非負整数 n を受け取り、n! = n × (n − 1) × · · · × 2 × 1 を計算する。
=end
def b(n)
	begin
		n = n.to_i.abs
		result = 1
		while n > 0 do
			n -= 1
			result += (result * n)
		end
		return result
	rescue => e
		return e.message
	end
end

=begin
c. 非負整数 n と r(≤ n) を受け取り、nCr を計算する。
=end
def c(n,r)
	begin
		n = n.to_s.to_i.abs
		r = r.to_s.to_i.abs
		if r > n then raise "Error" end
		n_i = b(n)
		puts n_i
		r_i = b(r) * b(n - r)
		puts r_i
		return n_i / r_i
	rescue => e
		return e.message
	end
end

=begin
d. x と計算する項の数 n を与えて、次のテイラー展開を計算する
=end
def d(x, n)
	begin
		x = x.to_i.abs
		n = n.to_i.abs
		sin_x = 0.0
		cos_x = 0.0
		sw = 1
		result = []
		for i in 0..n do
			if i == 0 then
				cos_x += (x_n(x,i).to_s.to_d / b(i).to_s.to_d)
			elsif (i.to_s.to_d % 2.to_s.to_d) == 0 then
				cos_x += (x_n(x,i).to_s.to_d / b(i).to_s.to_d) if sw.positive?
				cos_x -= (x_n(x,i).to_s.to_d / b(i).to_s.to_d) if sw.negative?
			else
				sin_x += (x_n(x,i).to_s.to_d / b(i).to_s.to_d) if sw.positive?
				sin_x -= (x_n(x,i).to_s.to_d / b(i).to_s.to_d) if sw.negative?
				sw = sw * -1
			end
			puts(cos_x)
		end
		result.push(sin_x)
		result.push(cos_x)
	rescue => e
		return e
	end
end

=begin
=end
def x_n(x,n)
	begin
		n = n.to_s.to_i.abs
		r = r.to_s.to_i.abs
		result = 1
		for i in 1..n do
			result = result * x
		end
		return result
	rescue => e
		return e.message
	end
end

=begin
=end
def factorial(a)
	result = a.to_i.abs
	while a.to_i > 1 do
		result = result * a -= 1
		puts a
	end
	return result
end
