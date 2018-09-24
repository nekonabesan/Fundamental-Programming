require 'bigdecimal'
require 'bigdecimal/util'
class FpModule 
  #/-----------------------------------------------------------/
  # 正の整数 N を受け取り、N が素数なら true、
  # そうでなければ false を返す Ruby プログラム
  #/-----------------------------------------------------------/
  def judgePno(n)
    begin
      raise ArgumentError if n == nil || n == 0
      n = n.to_i.abs
      for i in 2..(n - 1) do
        return false if (n % i) == 0
      end
      return true
    rescue => e
      return e
    end
  end
end
