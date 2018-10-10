require 'bigdecimal'
require 'bigdecimal/util'

class FpPno
  #/-----------------------------------------------------------/
  # 正の整数 N を受け取り、N が素数なら true、
  # そうでなければ false を返す Ruby プログラム
  # return bool
  #/-----------------------------------------------------------/
  def judgePno(n)
    begin
      raise ArgumentError if n == nil || n == 0
      # n == 2 の場合、trueを返す
      n = n.to_i.abs
      return true if n == 2
      for i in 2..(n - 1) do
        return false if (n % i) == 0
      end
      return true
    rescue => e
      return e
    end
  end

  #/-----------------------------------------------------------/
  # 正の整数 N を受け取り、N が素数なら true、
  # そうでなければ false を返す Ruby プログラム
  # ※改良版
  #   検査をN/2までとする
  #   2の倍数(偶数)を検査対象から除外する
  # return bool
  #/-----------------------------------------------------------/
  def judgePno2(n)
    begin
      raise ArgumentError if n == nil || n == 0
      n = n.to_i.abs
      # n == 2 の場合、trueを返す
      return true if n == 2
      lim = n - 1
      lim = (n / 2) + 1 if (n / 2) > 2
      for i in 2..lim do
        return false if (n % i) == 0
      end
      return true
    rescue => e
      return e
    end
  end

end
