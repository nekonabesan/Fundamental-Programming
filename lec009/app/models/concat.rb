=begin
b. 「文字列を連結していく」クラス Concat。add(s) で文字列 s を今まで覚えているものに
連結する (最初は空文字列)。get で現在覚えている文字列を返す。reset で覚えている文
字列を空文字列にリセット。(文字列どうしを連結するのは「+」でできます。)
=end
class Concat
  def initialize
    @feeld = ""
  end

  def add(str)
    @feeld = @feeld + str.to_s
  end

  def get
    return @feeld
  end

  def reset
    @feeld = ""
  end

end
