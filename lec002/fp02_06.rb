require 'bigdecimal'
require 'bigdecimal/util'
class Fp02_06
  #/-----------------------------------------------------------/
  # 正の整数 N を受け取り、N が素数なら true、
  # そうでなければ false を返す Ruby プログラム
  #/-----------------------------------------------------------/
  def p(n)
    begin
      raise ArgumentError if n == nil || n == 0
      n = n.to_i.abs
      lim = n - 1
      lim = (n / 2) + 1 if n / 2 > 2 
      for i in 2..lim do
        return false if (n % i) == 0
      end
      return true
    rescue => e
      return e
    end
  end
end
