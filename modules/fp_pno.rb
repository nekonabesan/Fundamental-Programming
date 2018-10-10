require 'bigdecimal'
require 'bigdecimal/util'

class FpPno
  def initialize(n)
    @lim = n
    @chk = Array.new(n,true)
  end

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
  # ！！引数は奇数に限る。呼び出し元で読み飛ばしを実装する事！！
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

=begin
  b. 別の考え方として、N 未満の素数を打ち出すのに次の方針を用いるのはどうだろう。
  • 論理値が並んだ要素数 N の配列を作り、全部「真」に初期化。
  • 2 から始めて順次、その番号が「真」の値は素数として出力。
  • 2、4、6、…と、2 の倍数番目の部分を「偽」に変更。
  • 3、6、9、…と、3 の倍数番目の部分を「偽」に変更。
  • 同様に、素数を出力するごとにその倍数番目を「偽」に変更
=end
  #/-----------------------------------------------------------/
  # 既知の素数のN倍を配列として保持するメソッド
  # param number
  # return bool
  #/-----------------------------------------------------------/
  def notPnoInAry(i)
    begin
      raise ArgumentError if i.nil?
      j = i + 1
      while @lim >= j do
        @chk[j] = false if j % i == 0
        j += 1
      end
      return true
    rescue => e
      return e
    end
  end

  def chkNotPno(i)
    begin
      raise ArgumentError if i.nil?
      # 既知の素数の倍数(素数ではない)である場合「真」を返す
      return true if @chk[i] == false
      return false
    rescue => e
      return e
    end
  end

end
