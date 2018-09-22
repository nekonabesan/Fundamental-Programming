require 'bigdecimal'
require 'bigdecimal/util'

=begin
a. 2 つの異なる実数 a、b を受け取り、より大きいほうを返す。
=end
def a(a,b)
	begin
		result =  (a.to_s.to_d - b.to_s.to_d).negative? ? b : a
		return result
	rescue => e
		return e
	end
end

=begin
b. 3 つの異なる実数 a、b、c を受け取り、最大のものを返す。(やる気があったら 4 つでやっ
てみてもよいでしょう。)
=end
def b(a,b,c)
	begin
		result = a
		array = [b, c]
		array.each{|num| result = (result.to_s.to_d - num.to_s.to_d).negative? ? num : result}
		return result
	rescue => e
		return e
	end
end

=begin
c. 実数を 1 つ受け取り、それが正なら「’positive’」、負なら「’negative’」、零なら
「’zero’」という文字列を返す。(注意! 文字列は’…’ または"…"で囲んで指定します。)
=end
def c(n)
	begin
		result = nil
		if 0 > n.to_s.to_d then
			result = "negative"
		elsif n.to_s.to_d == 0.to_s.to_d then
			result = "zero"
		else
			result = "positive"
		end
		return result
	rescue => e
		return e
	end
end
