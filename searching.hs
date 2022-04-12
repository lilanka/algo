linearSearch :: Eq a => a -> [a] -> Maybe Int 
linearSearch _ [] = Nothing  
linearSearch value (x:xs) | value == x  = Just 0
                          | otherwise   = fmap (+ 1) (linearSearch value xs)
