=begin
c. 「最大 2 つ覚える」機能を持つクラス Memory2。put(x) で新しい内容を記憶させ、get で
取り出す。2 回取り出すと 2 回目はより古い内容が出てくる。取り出した値は忘れる。覚え
ている以上に取り出すと nil が返る (興味があれば「最大 N 個覚える」をやってもよい)。
=end
class Memory2
  def initialize
    @feeld1 = nil
    @feeld2 = nil
  end

  def put(n)
    @feeld2 = @feeld1
    @feeld1 = n
  end

  def get
    result = @feeld1
    @feeld1 = @feeld2
    @feeld2 = nil
    return result
  end

end
