require 'bigdecimal'
require 'bigdecimal/util'
class Fp02_06
  #/-----------------------------------------------------------/
  # 正の整数 N を受け取り、N が素数なら true、
  # そうでなければ false を返す Ruby プログラム
  #/-----------------------------------------------------------/
  def p(n)
    begin
      n = n.to_i.abs
      for i in 2..(n - 1) do
        return false if (n % i) == 0
      end
      return true
    rescue => e
      return e.message
    end
  end
end
