using System.Numerics;
using System.Security.Cryptography;
using System.Text;

namespace ElGamalSignature
{
    public class ElGamalSignature
    {
        // Các thuật toán băm
        private static readonly Dictionary<string, Func<HashAlgorithm>> HASH_ALGORITHMS = new()
    {
        { "MD5", () => MD5.Create() },
        { "SHA-1", () => SHA1.Create() },
        { "SHA-256", () => SHA256.Create() },
        { "SHA-384", () => SHA384.Create() },
        { "SHA-512", () => SHA512.Create() },
    };
        private static int MAX = 20;

        // Hàm băm chuỗi
        public static string HashString(string text, string mode)
        {
            using var hashAlgorithm = HASH_ALGORITHMS[mode]();
            var hash = hashAlgorithm.ComputeHash(Encoding.UTF8.GetBytes(text));
            return BitConverter.ToString(hash).Replace("-", "").ToLower();
        }

        // Tìm ước chung lớn nhất (GCD)
        public static int FindGcd(int a, int b)
        {
            return b == 0 ? a : FindGcd(b, a % b);
        }

        // Kiểm tra số nguyên tố
        public static bool CheckPrime(int n)
        {
            if (n < 2) return false;
            for (int i = 2; i <= Math.Sqrt(n); i++)
            {
                if (n % i == 0) return false;
            }
            return true;
        }

        // Tìm số nguyên tố ngẫu nhiên
        public static int FindPrime()
        {
            Random rand = new();
            while (true)
            {
                int result = rand.Next((int)Math.Pow(2, MAX - 2), (int)Math.Pow(2, MAX - 1) - 1);
                if (CheckPrime(result)) return result;
            }
        }

        // Tính a^b mod n
        public static BigInteger PowMod(BigInteger a, BigInteger b, BigInteger n)
        {
            return BigInteger.ModPow(a, b, n);  // Using built-in ModPow for efficiency and correctness
        }

        // Tính nghịch đảo mô-đun
        public static BigInteger ModInverse(BigInteger a, BigInteger m)
        {
            BigInteger m0 = m;
            BigInteger y = 0, x = 1;

            if (m == 1)
                return 0;

            while (a > 1)
            {
                BigInteger q = a / m;
                BigInteger t = m;

                m = a % m;
                a = t;
                t = y;

                y = x - q * y;
                x = t;
            }

            if (x < 0)
                x += m0;

            return x;
        }

        // Tạo số alpha ngẫu nhiên
        public static BigInteger GenAlpha(BigInteger p)
        {
            Random rand = new();
            return rand.Next(2, (int)(p - 1));
        }

        // Tạo số a ngẫu nhiên
        public static BigInteger GenA(BigInteger p)
        {
            Random rand = new();
            return rand.Next(2, (int)(p - 2));
        }

        // Tạo số k ngẫu nhiên sao cho gcd(k, p-1) = 1
        public static BigInteger GenK(BigInteger p)
        {
            Random rand = new();
            while (true)
            {
                BigInteger k = rand.Next(1, (int)(p - 2));
                if (FindGcd((int)k, (int)(p - 1)) == 1)
                {
                    return k;
                }
            }
        }

        // Tạo khóa ElGamal
        public static List<BigInteger> CreateKey()
        {
            BigInteger p = FindPrime();
            BigInteger alpha = GenAlpha(p);
            BigInteger a = GenA(p);
            BigInteger beta = PowMod(alpha, a, p);
            BigInteger k = GenK(p);
            BigInteger gamal = PowMod(alpha, k, p);

            return [p, alpha, a, beta, k, gamal];
        }

        // Tạo chữ ký
        public static List<BigInteger> CreateSignature(string text, string hash, BigInteger gamal, BigInteger a, BigInteger k, BigInteger p)
        {
            string textHash = HashString(text, hash);
            List<BigInteger> result = new();
            BigInteger kInv = ModInverse(k, p - 1);

            foreach (char c in textHash)
            {
                BigInteger m = (int)c;
                // Fixed signature equation: s = k^(-1)(m - a*r) mod (p-1)
                BigInteger s = (kInv * (m - a * gamal)) % (p - 1);
                if (s < 0) s += (p - 1);
                result.Add(s);
            }

            return result;
        }
        //"0cc175b9c0f1b6a831c399e269772661"
        public static bool VerifySignature(string text, string hash, string signStr, BigInteger beta, BigInteger gamal, BigInteger alpha, BigInteger p)
        {
            string textHash = HashString(text, hash);
            List<int> messageHash = textHash.Select(c => (int)c).ToList();

            string trimmed = signStr.Trim('[', ']');
            List<BigInteger> signature;
            try
            {
                signature = trimmed.Split(',').Select(BigInteger.Parse).ToList();
            }
            catch
            {
                return false;
            }

            if (messageHash.Count != signature.Count) return false;

            for (int i = 0; i < messageHash.Count; i++)
            {
                // Verify equation: α^m ≡ β^r * r^s (mod p)
                BigInteger left = PowMod(alpha, messageHash[i], p);
                BigInteger right = (PowMod(beta, gamal, p) * PowMod(gamal, signature[i], p)) % p;

                if (left != right) return false;
            }

            return true;
        }
    }
}
