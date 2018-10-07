require __dir__ + "/spec_helper"
require __dir__ + '/../fp10_01.rb'


describe "演習 1" do
  context "a" do
    it "a(10)" do
      results = a(10)
      expect(results).to eq 55
    end
    it "a(100)" do
      results = a(100)
      expect(results).to eq 5050
    end
    it "a(22)" do
      results = a(22)
      expect(results).to eq 253
    end
    it "a(nil)" do
      results = a(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "b" do
    it "b('stirng')" do
      results = b('string')
      expect(results).to match("string")
    end
    it "b('Hallo World!!')" do
      results = b('Hallo World!!')
      expect(results).to match("Hallo World!!")
    end
    it "b('0123456789')" do
      results = b('0123456789')
      expect(results).to match("0123456789")
    end
    it "b(nil)" do
      results = b(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "c" do
    it "" do
      results = c("string")
      expect(results).to match("gnirts")
    end
    it "" do
      results = c('Hallo World!!')
      expect(results).to match("!!dlroW ollaH")
    end
    it "" do
      results = c('0123456789')
      expect(results).to match("9876543210")
    end
    it "c(nil)" do
      results = c(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "d" do
    it "d('string')" do
      results = d("string")
      expect(results).to match("sttrrriiiinnnnngggggg")
    end
    it "d('Hallo World!!')" do
      results = d("Hallo World!!")
      expect(results).to match("Haalllllllooooo      WWWWWWWoooooooorrrrrrrrrllllllllllddddddddddd!!!!!!!!!!!!!!!!!!!!!!!!!")
    end
    it "d('0123456789')" do
      results = d("0123456789")
      expect(results).to match("0112223333444445555556666666777777778888888889999999999")
    end
    it "" do
      results = d(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "listcat" do
    it "listcat(nil)" do
      results = listrev(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "f" do
    it "listrev(nil)" do
      results = listrev(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
